package UI;

import javax.swing.*;
import java.awt.*;

public class GUI extends JFrame {
    private JList<String> areaTexto;
    private JTextField input;
    private DefaultListModel<String> aux;

    public GUI(){
        super("Gerenciador de Tarefas Simples");

        aux = new DefaultListModel<>();
        areaTexto = new JList<>(aux);
        input = new JTextField(50);
        setSize(500, 300);
        setLayout(new BorderLayout(10, 10));

        JPanel areaBtn = new JPanel();
        JPanel L_Inp = new JPanel(new BorderLayout(10, 100));
        JScrollPane scrollPane = new JScrollPane(areaTexto);

        JButton addTarefa = new JButton("Adicionar Tarefa");
        JButton limpar = new JButton("Limpar Dados");
        JButton removerSelecionado = new JButton("Remover Selecionado");
        JLabel labelTarefa = new JLabel("Tarefa:");

        limpar.addActionListener(e -> {
            aux.removeAllElements();
            areaTexto.getModel();
            });
        addTarefa.addActionListener(e -> addTarefas());
        removerSelecionado.addActionListener(e -> eliminarREgistro());

        areaBtn.add(addTarefa);
        areaBtn.add(removerSelecionado);
        areaBtn.add(limpar);

        L_Inp.add(labelTarefa, BorderLayout.WEST);
        L_Inp.add(input, BorderLayout.CENTER);

        add(L_Inp, BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);
        add(areaBtn, BorderLayout.SOUTH);

        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    private void eliminarREgistro() {
        String selecionado = areaTexto.getSelectedValue();
        aux.removeElement(selecionado);
        areaTexto.getModel();
    }

    private void addTarefas() {
        String minhaTarefa = (String) input.getText().trim();
        aux.addElement(minhaTarefa);
        areaTexto.getModel();
        input.setText("");
    }
}