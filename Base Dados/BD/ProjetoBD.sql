create database if not exists ProjectDB;
use ProjectDB;

-- criacao das tabelas 
create table if not exists Stock(
	id_Stock int not null primary key auto_increment,
    produto varchar(255) default 'Flores',
    quantidade int
);
alter table Stock add column tipo varchar(100);

create table if not exists Funcionario(
	id_Utilizador int not null primary key auto_increment,
    nome varchar(255) not null,
    cargo varchar(255),
    salario decimal(7,2)
);

create table if not exists Funeraria(
	id_Funeraria int not null primary key auto_increment,
    nome varchar(255) default 'Funeraria Freitas&Fortes',
    morada varchar(255) default 'Mindelo',
    id_Stock int not null,
    id_Utilizador int not null,
    contacto varchar(50) not null,
    constraint Foreign key fk_FunerariaStock(id_Stock) references Stock(id_Stock) on delete cascade on update cascade,
    constraint foreign key fk_FunerariaFunc(id_Utilizador) references funcionario(id_Utilizador) on delete cascade on update cascade
);

create table if not exists Fornecedores(
	id_Fornecedor int not null primary key auto_increment,
    nome varchar(255) not null,
    contacto varchar(50) not null,
    morada varchar(255),
    preco decimal 
);

create table if not exists Encomenda(
	id_Encomenda int not null primary key auto_increment,
    data_Encomenda date,
    id_Funeraria int not null,
    id_Fornecedor int not null,
    constraint Foreign key fk_encomendaFunk(id_Funeraria) references Funeraria(id_Funeraria) on delete cascade on update cascade,
    constraint foreign key fk_encomendaForn( id_Fornecedor) references Fornecedores( id_Fornecedor) on delete cascade on update cascade
);

create table if not exists Flores(
	id_flor int not null primary key auto_increment,
    nome varchar(255) not null,
    tipo varchar(255) default 'Artificial',
    preco decimal(10, 2),
    id_Encomenda int not null,
    constraint foreign key fkencFlor(id_Encomenda) references Encomenda(id_Encomenda) on delete cascade on update cascade
);

-- criacao dos triggers
delimiter //
create trigger verificar_estoque
before insert on Encomenda
for each row
begin
    declare qtd int;
    select s.quantidade into qtd from Stock s inner join Funeraria f
    on F.id_Stock = s.id_Stock where f.id_funeraria = new.id_funeraria;

    if qtd <= 0 then
        signal sqlstate '45000' set message_text = 'ERROR: Estoque insuficiente para esta encomenda.';
    end if;
end;
//
delimiter ;

delimiter //
create trigger Validar_salario
before insert on Funcionario
for each row
begin
    if new.salario < 15000 or new.salario > 60000 then
        signal sqlstate '45000' set message_text = 'ERROR: Salario fora do intervalo permitido.';
    end if;
end;
//
delimiter ;

delimiter //
create trigger atualizar_estoque_encomenda
after insert on Encomenda
for each row
begin
    declare id_Alvo int; -- ou seja o id que referenciara o tipo no stock

    select f.id_Stock into id_Alvo from Funeraria f where f.id_Funeraria = new.id_Funeraria;

    update Stock
    set quantidade = quantidade + 1
    where id_Stock = id_Alvo;
end;
//
delimiter ;

-- criacao das views
create view EstoqueFuneraria as
select 
    F.nome as Funeraria,
    S.produto,
    S.quantidade
from Funeraria F inner join Stock S on F.id_Stock = S.id_Stock;

create view FloresEncomendadas as
select 
    FL.id_flor,
    FL.nome as Flor,
    FL.tipo,
    FL.preco,
    E.id_Encomenda,
    E.data_Encomenda
from Flores FL inner join Encomenda E on FL.id_Encomenda = E.id_Encomenda;

create view FuncionariosFuneraria as
select 
    FU.nome as Funcionario,
    FU.cargo,
    FN.nome as Funeraria,
    FN.morada
from Funcionario FU
join Funeraria FN on FU.id_Utilizador = FN.id_Utilizador;


-- criacao dos procedimentos
delimiter //
create procedure consultarEstoque(in tipoBusca varchar(255))
begin
	select quantidade from Stock where tipo like concat('%', tipoBusca, '%');
end //
delimiter ;

delimiter //
create procedure ListarFloresTipo(in tipoFlor varchar(100))
begin
    select 
        id_flor, nome, preco
        from Flores where tipo like concat('%', tipoFlor, '%');
end;
//

delimiter ;

-- criacao das funcoes
delimiter //
create function QuantidadeFloresTipo(tipoFlor varchar(100))
returns int
deterministic
begin
    declare qtd int;
    select count(*) into qtd from Flores where tipo = tipoFlor;
    return qtd;
end;
//
delimiter ;

delimiter //
create function MaiorSalario()
returns decimal(7,2)
deterministic
begin
    declare resultado decimal(7,2);
    select max(salario) into resultado from Funcionario;
    return resultado;
end;
//

create function MenorSalario()
returns decimal(7,2)
deterministic
begin
    declare resultado decimal(7,2);
    select min(salario) into resultado from Funcionario;
    return resultado;
end;
//

create function MediaSalarial()
returns decimal(7,2)
deterministic
begin
    declare resultado decimal(7,2);
    select avg(salario) into resultado from Funcionario;
    return resultado;
end;
//
delimiter ;

-- comandos para teste
insert into Stock (produto, quantidade, tipo) values ('Flores', 10, 'Rosa');
insert into Stock (produto, quantidade, tipo) values ('Flores', 0, 'Orquídea');

insert into Funcionario (nome, cargo, salario) values ('Ana Santos', 'Gerente', 30000);
insert into Funcionario (nome, cargo, salario) values ('Carlos Lima', 'Florista', 18000);

insert into Funeraria (nome, morada, id_Stock, id_Utilizador, contacto)
values ('Funeraria Vida Eterna', 'São Vicente', 1, 1, '99887766');
insert into Funeraria (nome, morada, id_Stock, id_Utilizador, contacto)
values ('Paz Celestial', 'Mindelo', 2, 2, '88776655');

insert into Fornecedores (nome, contacto, morada, preco)
values ('Flor & Cia', '99881234', 'Santo Antão', 250.00);
insert into Fornecedores (nome, contacto, morada, preco)
values ('Flores Tropicais', '99889999', 'Praia', 180.50);

insert into Encomenda (data_Encomenda, id_Funeraria, id_Fornecedor)
values (curdate(), 1, 1);

insert into Flores (nome, tipo, preco, id_Encomenda)
values ('Rosa Vermelha', 'Rosa', 50.00, 1);
insert into Flores (nome, tipo, preco, id_Encomenda)
values ('Rosa Branca', 'Rosa', 55.00, 1);

select * from Stock;
select * from EstoqueFuneraria;
select * from FloresEncomendadas;
select * from FuncionariosFuneraria;

call consultarEstoque('Rosa');
call ListarFloresTipo('Rosa');

select QuantidadeFloresTipo('Rosa') as TotalRosas;
select MaiorSalario() as Maior;
select MenorSalario() as Menor;
select MediaSalarial() as Media;

select * from Stock;
select * from Funcionario;
select * from Funeraria;
select * from Fornecedores;
select * from Encomenda;
select * from Flores;