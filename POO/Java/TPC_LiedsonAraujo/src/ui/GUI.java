package ui;
import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class GUI extends JFrame {
    private final JTextField inputUser;
    private final JPasswordField pass;

    public GUI(){
        super("TPC-Criar Grelha");
        setLayout(new GridLayout(5, 1, 10,10));
        setSize(400,600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JLabel icon = new JLabel("Teste", SwingConstants.CENTER);
        icon.setSize(20,20);
        icon.setBorder(new LineBorder(new Color(0x000000)));

        JPanel label_Input = new JPanel(new BorderLayout(10,10));
        JLabel user = new JLabel("User:");
        inputUser = new JTextField();
        inputUser.setSize(250, 8);
        inputUser.setMaximumSize(new Dimension(250,10));
        inputUser.setMinimumSize(new Dimension(250, 10));

        label_Input.add(user, BorderLayout.NORTH);
        label_Input.add(inputUser, BorderLayout.CENTER);

        JPanel label_Pass = new JPanel(new BorderLayout(10,10));
        JLabel userPass = new JLabel("Password:");
        pass = new JPasswordField();
        pass.setSize(250, 10);
        pass.setMaximumSize(new Dimension(250,10));
        pass.setMinimumSize(new Dimension(250, 10));

        label_Pass.add(userPass, BorderLayout.NORTH);
        label_Pass.add(pass, BorderLayout.CENTER);

        JButton btn = new JButton("Login");
        btn.setSize(new Dimension(250, 10));
        btn.setMaximumSize(new Dimension(250,10));
        btn.setMinimumSize(new Dimension(250, 10));
        btn.addActionListener(e -> validarCredencias());
        btn.setBackground(new Color(0xF02864FF, true));
        btn.setForeground(new Color(255,255,255));


        add(icon);
        add(label_Input);
        add(label_Pass);
        add(btn);

        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void validarCredencias() {
        String user = inputUser.getText().trim();
        String passWord = new String(pass.getPassword());

        inputUser.setText("");
        pass.setText("");


        if(user.equals("Liedson") && passWord.equals("Teste")){
            JOptionPane.showMessageDialog(null,
                    "Dados Validos");
        }else{
            JOptionPane.showMessageDialog(null,
                    "Erro dados nao corretos");
        }
    }
}
