-- sobre VIEW

-- exercicio 1
CREATE VIEW CustomerOrderSummary AS
    SELECT
        c.customerNumber,
        c.customerName,
        c.contactFirstName,
        c.contactLastName,
        COUNT(DISTINCT o.orderNumber) AS TotalOrders,
        SUM(od.quantityOrdered * od.priceEach) AS TotalAmountSpent
    FROM
        customers c
        INNER JOIN orders o ON c.customerNumber = o.customerNumber
        INNER JOIN orderdetails od ON o.orderNumber = od.orderNumber
    GROUP BY c.customerNumber;

-- exercicio 2
CREATE VIEW ProductsLowInStock AS
    SELECT
        productCode,
        productName,
        MSRP AS Preco_VendaSugerido,
        quantityInStock
FROM
    products WHERE quantityInStock <= 100;
