-- exercicio 1
create database Ficha02;
use Ficha02;

create table fabricantes(
	codigo int not null primary key,
    nome varchar(25) not null
);

create table produtos(
	codigo int not null primary key,
    nome varchar(25),
    preco decimal(10,0),
    Fabricante int not null,
    foreign key(Fabricante) references fabricantes(codigo)
);

desc produtos;
desc fabricantes;

-- exercicio 2
insert into fabricantes(codigo, nome) values(1, 'Sony'),
(2, 'Creative Labs'),
(3, 'Hewlett-Packard'),
(4, 'Iomega'),
(5, 'Fujitsu'),
(6, 'Winchester');

insert into produtos values(1, 'Hard drive', 240, 5),
(2, 'Memory', 120, 6),
(3, 'Zip Drive', 150, 4),
(4, 'Floppy disk', 4, 6),
(5, 'Monitor', 240, 1),
(6, 'DVD Drive', 180, 2),
(7, 'CD Drive', 90, 2),
(8, 'Pinter', 270, 3),
(9, 'Toner cartridge', 66, 3),
(10, 'DVD Burner', 180, 2);

select * from produtos;
select * from fabricantes;

-- exercicio 4
select nome from produtos;

-- ecercicio 5
select nome, preco from produtos;

-- exercicio 6
select nome, preco from produtos order by preco asc limit 1;

-- exercicio 7
select nome from produtos where preco <= 200;

-- exercicio 8
select * from produtos where preco between 60 and 120;

-- exercicio 9
select * from produtos where nome like '%drive%';

-- exercicio 10
select * from produtos where nome like '%r'; 

-- exercicio 11
update produtos set nome = 'Impressora Laser' where codigo = 8;

-- exercicio 12
update produtos set preco = preco - (preco * 10/100);

-- exercicio 13
update produtos set preco = preco * 0.9