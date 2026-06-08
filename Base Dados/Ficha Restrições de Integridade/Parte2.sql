USE aula16;

-- exercicio 2
CREATE TABLE Pagamento (
    id_pagamento INT PRIMARY KEY,
    metodo VARCHAR(50) NOT NULL CHECK (metodo IN ('dinheiro', 'cartão', 'transferência')),
    valor DECIMAL(10,2) NOT NULL CHECK (valor > 0),
    estado VARCHAR(20) CHECK (estado IN ('pago', 'pendente'))
);

INSERT INTO Pagamento (id_pagamento, metodo, valor, estado) VALUE(1, 'cheque', -10, 'pendente');
-- nao introduza os dados porque o -10 na e aceito e o cheque nao pertence ao metado

-- exercicio 3
-- criei esta tabela amais para fazer a relacao
CREATE TABLE fornecedores (
    id_fornecedor INT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    contato VARCHAR(100)
);
INSERT INTO fornecedores (id_fornecedor, nome, contato) VALUE (500, 'Liedson', '123456789');

CREATE TABLE Fornecimentos (
    id_fornecimento INT PRIMARY KEY,
    id_produto INT NOT NULL,
    id_fornecedor INT NOT NULL,
    UNIQUE (id_produto, id_fornecedor),
    CONSTRAINT FOREIGN KEY (id_produto) REFERENCES produtos(id_produto),
    CONSTRAINT FOREIGN KEY (id_fornecedor) REFERENCES fornecedores(id_fornecedor)
);
INSERT INTO Fornecimentos (id_fornecimento, id_produto, id_fornecedor) VALUES (1, 1, 500);
INSERT INTO Fornecimentos (id_fornecimento, id_produto, id_fornecedor) VALUES (2, 1, 500);
-- a segunda insercao dos dados nao e permetido por causa da unicidade

-- exericio 4
CREATE TABLE Avaliacoes (
    id_avaliacao INT PRIMARY KEY,
    comentario TEXT,
    pontuacao INT DEFAULT 3 CHECK (pontuacao BETWEEN 1 AND 5)
);

INSERT INTO Avaliacoes (id_avaliacao, comentario) VALUES (1, 'Ótimo serviço!');
-- coloca o 3 como default
INSERT INTO Avaliacoes (id_avaliacao, comentario, pontuacao) VALUES (2, 'Muito bom!', 6);
-- nao deixar introduzir porque a pontuacao tem de estar entre 1 a 5 