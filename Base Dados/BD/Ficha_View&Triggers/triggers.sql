-- sobre triggers
-- exercicio 1
/*
1. Crie um gatilho (trigger) chamado trg_UpdateCreditLimitAfterPayment que é acionado após a
inserção de um novo registro na tabela payments. Este gatilho deve diminuir o creditLimit do
cliente correspondente na tabela customers pelo amount do pagamento.
*/
delimiter //
create trigger trg_UpdateCreditLimitAfterPayment
	after insert on payments -- atualizar a tabela customers depois da inserir dados na tabela payments
	for each row -- executar para cada linha a atualizacao
	begin
		update customers
		set creditLimit = creditLimit - new.amount -- atualizar o creditLimit com o novo valor intruduzido em amount
		where customerNumber = new.customerNumber; -- onde a atualizacao sera feita
	end//
delimiter ;

select creditLimit, customerNumber, customerName from customers;
select * from payments;
desc payments;
insert into payments value(103, 'Teste','2025-06-09', 10000.15); -- comando para teste

-- exercicio 2
 /*
 2. Crie um gatilho (trigger) chamado trg_PreventNegativeStock que é acionado antes da
atualização de um registro na tabela products. Este gatilho deve verificar se a nova
quantityInStock seria menor que zero. Se for, deve impedir a atualização (ou seja, gerar um
erro) para garantir que o estoque nunca fique negativo.
 */

delimiter //
create trigger trg_PreventNegativeStock
	before update on products -- verificar na tabela products antes da insersao dos dados
	for each row -- executar para cada linha a instrucao
	begin
		if new.quantityInStock < 0 then -- verificar se o stock a ser introduzido e < 0
			signal sqlstate '45000' -- desparar um erro de insersao
            set message_text = "Erro ao introduzir os valores"; -- mostrar uma mensagem ao utilizador
		end if;
	end//
delimiter ;

desc products; 
select productCode from products;
select * from products where productCode = 'S50_1341';

update products set quantityInStock = -5 where productCode = 'S50_1341'; -- comando para teste
