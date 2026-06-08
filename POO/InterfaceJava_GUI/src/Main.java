import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame mainWindow = new JFrame("Primeiro exemplo");

        mainWindow.setSize(800,  800); //Tamanho das minhas janelas em px

        JLabel titulo1 = new JLabel("Aula de POO", JLabel.CENTER); //Jlabel criar um corpo para minha janela ele possui algumas constantes Jlabel.CENTER / RIGHT/ LEFT
        JLabel titulo2 = new JLabel("Java Swing",  JLabel.CENTER);
        JLabel titulo3 = new JLabel("Lab Programacao 14:30 as 17:30");
        JLabel titulo4 = new JLabel("Visto", new ImageIcon("check.png"), JLabel.LEFT);

        FlowLayout layout = new FlowLayout();// criar um layout da minha janela do tipo que mostra as coisas uma aseguir a outra
        mainWindow.setLayout(layout);//atribuir a minha janela o meu layout

        titulo2.setPreferredSize(new Dimension(65, 20));
        titulo2.setBackground(new Color(33, 97, 10, 211));
        titulo2.setOpaque(true);

        titulo4.setBackground(new Color(255, 255, 255));
        titulo4.setOpaque(true);
        titulo4.setPreferredSize(new Dimension(120, 130));

        titulo1.setPreferredSize(new Dimension(150, 25)); //dimensao do label na minha janela
        titulo1.setBackground(new Color(6, 169, 245, 174)); //cor de fundo
        titulo1.setOpaque(true); //transparencia da cor ou seja mostrar a cor de fundo do label
        

        mainWindow.add(titulo1); // adicionar a minha janela o titulo1
        mainWindow.add(titulo2);
        mainWindow.add(titulo3);
        mainWindow.add(titulo4);

        mainWindow.setVisible(true); // visiblidade da janela ou seja para mostrar ou nao
    }
}