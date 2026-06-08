package ui;
import perfis.*;
import principal.Main;

import javax.swing.*;
import java.awt.*;

public class GUI extends JFrame {

    private JList<PessoaUniversidade> listaPersonagens;
    private JTextArea areaAtividades;
    private DefaultListModel modeloLista;

    public GUI(){
        super("Universidade Simultor");

        setSize(800, 600);
        setLayout(new BorderLayout());

        modeloLista = new DefaultListModel<>();
        listaPersonagens = new JList<>(modeloLista);
        areaAtividades = new JTextArea();

        areaAtividades.setEditable(false);

        JScrollPane eLista = new JScrollPane(listaPersonagens); //adicionar scrolbar na lista
        JScrollPane eArea = new JScrollPane(areaAtividades);

        JButton addPersonagem = new JButton("Adicionar personagem");
        JButton executar = new JButton("Executar");
        JButton delete = new JButton("Eliminar Registro");
        JButton clear = new JButton("Apagar dados");
        JButton reset = new JButton("Reset");

        JPanel areaBotoes = new JPanel();
        areaBotoes.add(addPersonagem);
        areaBotoes.add(delete);
        areaBotoes.add(executar);
        areaBotoes.add(clear);

        JPanel topo = new JPanel();
        topo.setLayout(new BorderLayout());

        topo.add(new JLabel("Simulador de Universidade"),  BorderLayout.WEST);
        topo.add(new JLabel("Liedson Gomes Araujo", SwingConstants.CENTER), BorderLayout.CENTER);
        topo.add(reset, BorderLayout.EAST);

        addPersonagem.addActionListener((e)-> addPersonagens());
        delete.addActionListener((e) -> eliminarR());
        executar.addActionListener((e) -> mostrarDetalhes());
        clear.addActionListener(e -> {
            areaAtividades.setText(""); //Limpar o meu textera
            modeloLista.removeAllElements(); //elimanar todos os elementos da minha lista de Pessoas
        });
        reset.addActionListener(e -> {
            dispose();//fechar essa janela
            Main.main(new String[0]); //chamar o main novamente
        });

        JPanel baixo = new JPanel(new BorderLayout());
        baixo.add(areaBotoes, BorderLayout.NORTH);
        baixo.add(new JLabel("Todos os Reservados \u00A9 Liedson Gomes Araujo", SwingConstants.CENTER), BorderLayout.SOUTH);

        add(topo, BorderLayout.NORTH);
        add(eLista, BorderLayout.WEST);
        add(eArea, BorderLayout.CENTER);
        add(baixo, BorderLayout.SOUTH);

        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);

    }

    private void addPersonagens(){
        modeloLista.addElement(new EstudanteEsperto("Manuel"));
        modeloLista.addElement(new ProfessorZen("Carla"));
        modeloLista.addElement(new ProfessorExigente("Antonio"));
        modeloLista.addElement(new EstudantePreguicoso("Joao"));
        modeloLista.addElement(new ProfessorImprovisador("Joana"));
        modeloLista.addElement(new EstudanteFestas("Alberto"));
    }

    private void mostrarDetalhes(){
        try {
            PessoaUniversidade selecionado = listaPersonagens.getSelectedValue(); //apanhar a referencia do meu objeto selecionado
            areaAtividades.append(selecionado.realizarAtividade() + "\n"); //adicionar contiudo ao meu textera
        }catch (NullPointerException e){ //caso nao houver nenhum selecionado
            JOptionPane.showMessageDialog(null, "Nenhum registro selecionado");
        }
    }

    private void eliminarR(){
            PessoaUniversidade selecionado = listaPersonagens.getSelectedValue();

            if (selecionado != null)
                modeloLista.removeElement(selecionado); //eliminar o registro selecionado na lista
            else
                JOptionPane.showMessageDialog(null, "Nenhum registro selecionado");
    }

}
