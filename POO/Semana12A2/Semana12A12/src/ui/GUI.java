package ui;
import perfis.*;
import principal.Main;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class GUI extends JFrame {

    private JList<PessoaUniversidade> listaPersonagens;
    private JTextArea areaAtividades;
    private DefaultListModel modeloLista;
    private ArrayList<PessoaUniversidade> aux;

    public GUI(){
        super("Universidade Simultor");

        setSize(800, 600);
        setLayout(new BorderLayout());

        modeloLista = new DefaultListModel<>();
        listaPersonagens = new JList<>(modeloLista);
        areaAtividades = new JTextArea();
        aux = new ArrayList<>();

        areaAtividades.setEditable(false);

        JScrollPane eLista = new JScrollPane(listaPersonagens); //adicionar scrolbar na lista
        JScrollPane eArea = new JScrollPane(areaAtividades);

        JComboBox<String> filtro= new JComboBox<>(new String[] { "All", "Estudantes", "Professores" });

        filtro.addActionListener(e -> {
            String tipo = (String) filtro.getSelectedItem(); //selecionar a opcao no filtro
            modeloLista.removeAllElements(); //eliminar o buffer os seja os elementos para mostrar apenas os filtrados

            for (PessoaUniversidade p : aux) {
                String classe = p.getClass().getSimpleName(); //Apanhar nome da classe
                if (tipo.equals("All") || (tipo.equals("Estudantes") && classe.startsWith("Estudante")) || (tipo.equals("Professores") && classe.startsWith("Professor"))) {
                    modeloLista.addElement(p);//add os filtrados
                }
            }
        });


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
        areaBotoes.add(filtro);

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

        aux.add(new EstudanteEsperto("Manuel"));
        aux.add(new ProfessorZen("Carla"));
        aux.add(new ProfessorExigente("Antonio"));
        aux.add(new EstudantePreguicoso("Joao"));
        aux.add(new ProfessorImprovisador("Joana"));
        aux.add(new EstudanteFestas("Alberto"));
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
