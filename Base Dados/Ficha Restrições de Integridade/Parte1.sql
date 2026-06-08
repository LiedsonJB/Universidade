create database if not exists Aula16;
use Aula16;

-- Exercicio 1.1
create table if not exists  cliente(
	id_cliente int auto_increment primary key,
    nome varchar(255) not null,
    email varchar(255) unique,
    idade int check(idade >= 18)
);

-- Exercicio 1.2
insert into cliente value (1, 'Liedson', 'laraujo@uta.cv', 17);
-- nao deixa introduzir porque a idade tem que ser >= 18 onde e verificado pela metado check table

-- exercicio 2.1
create table pedidos(
	id_pedido int primary key,
    data_pedido date,
    id_cliente int,
    Constraint foreign key (id_cliente) references cliente(id_cliente)
);

-- exercicio 2.2
insert into cliente value (1 ,'Liedson', 'laraujo@uta.cv', 19);
insert into pedidos value (1, '2025-12-15', 1);

delete from cliente where id_cliente = 1;
-- nao deixar eliminar porque ele esta relacionado com a tabela pedidos

-- exercicio 3.1
create table produtos(
	id_produto int auto_increment primary key,
    nome varchar(255) not null,
    preco decimal(10,2) not null default 0.00,
    quantidade int default 1
);

-- exercicio 3.2
insert into produtos(nome) value ('PC game');
select * from produtos;
-- mostre com os valores definidos com o default

-- exercicio 4.1
create table departamento(
	id_departamento int auto_increment primary key,
    nome varchar(200) not null
);
create table funcionario(
	id_funcionario int auto_increment primary key,
    nome varchar(200) not null,
    id_departamento int,
    Constraint foreign key (id_departamento) references departamento(id_departamento)
);

-- exercicio  4.1
INSERT INTO departamento (nome) VALUE ('LEIT');
INSERT INTO funcionario (id_funcionario, nome, id_departamento) VALUES (1, 'Liedson', 1);
INSERT INTO funcionario (id_funcionario, nome, id_departamento) VALUES (2, 'Carlos', 1);

delete from departamento where id_departamento = 1;
-- nao deixa elimanar os dados no departamento entao nao elimina nenhum funcionario    