create database BD_SQL_1;

use BD_SQL_1;

create table CadFun(
CodFun integer not null primary key,
Nome varchar(40)not null,
Depto char(2),
Funcao char(20),
Salario decimal(10,2)
);

show tables;

INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(12,'Carlos Alberto','3','Vendedor',1530.00);
INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(37,'Augusto Souza','4','Programador',1050.00);
INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(57,'John Smith','4','Programador',2000.00);

select * from CadFun;

select Nome,CodFun from CadFun where depto='4'and salario>=1000.00;

update CadFun set Salario=35000.00 where CodFun=37;

delete from CadFun where CodFun=57;

alter table CadFun add DataAdmicao;