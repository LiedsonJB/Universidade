-- Ficha sobre procedimentos;
-- Exercicio 3
DELIMITER
//

CREATE PROCEDURE AddProductToOrder (
    IN p_orderNumber INT,
    IN p_productCode VARCHAR
(15),
    IN p_quantityOrdered INT
)
BEGIN

    INSERT INTO orderdetails
        (
        orderNumber, productCode, quantityOrdered, priceEach, orderLineNumber
        )
    SELECT
        p_orderNumber,
        p_productCode,
        p_quantityOrdered,
        MSRP,
        IFNULL(MAX(orderLineNumber), 0) + 1
    FROM
        products
        LEFT JOIN orderdetails ON orderdetails.orderNumber = p_orderNumber
    WHERE
        products.productCode = p_productCode;

    -- Atualizar o stock do produto
    UPDATE products
    SET quantityInStock = quantityInStock - p_quantityOrdered
    WHERE productCode = p_productCode;
END
//

DELIMITER ;



CALL AddProductToOrder
(10100, 'S10_1678', 5);

