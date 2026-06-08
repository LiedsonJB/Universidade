use classicmodels;
-- sobre VIEW
-- exercicio 1
/*
1. Crie uma view chamada CustomerOrderSummary que exibe as seguintes informações para
cada cliente: customerNumber, customerName, contactFirstName, contactLastName,
TotalOrders (contagem de pedidos), e TotalAmountSpent (soma de todos os quantityOrdered
* priceEach dos detalhes dos pedidos).
*/
create view CustomerOrderSummary as
    select     				-- selecionar os campos:
        c.customerNumber,
        c.customerName,
        c.contactFirstName,
        c.contactLastName,
        count(distinct o.orderNumber) as TotalOrders, -- distinguir os o.orderLineNumber, conta-los e renomiando para TotalOrders
        sum(od.quantityOrdered * od.priceEach) as TotalAmountSpent -- fazer o produto entre os valares dos campos, soma-los no fim e renomiar para TotalAmountSpent
    from
        customers c
        inner join orders o on c.customerNumber = o.customerNumber -- selecionar os valores apenas onde c.customerNumber = o.customerNumber
        inner join orderdetails od on o.orderNumber = od.orderNumber -- selecionar os valores apenas onde o.orderNumber = od.orderNumber
    group by c.customerNumber; -- agrupar os resultados por c.customerNumber

select * from CustomerOrderSummary; -- ver a solucao

-- exercicio 2
/*
2. Crie uma visualização (view) chamada ProductsLowInStock que lista productCode,
productName, MSRP (como Preço de Venda Sugerido) e quantityInStock para todos os
produtos onde a quantityInStock é menor ou igual a 100.
*/
create view ProductsLowInStock as
    select           -- selecionar os campos:
        productCode,
        productName,
        MSRP as Preco_Venda_Sugerido, -- renomear o campo MSRP para Preco_Venda_Sugerido
        quantityInStock
	from
		products where quantityInStock <= 100; -- selecionar apenas onde quantityInStock <= 100
        
select * from ProductsLowInStock; -- comando para teste