import java.sql.*;
public class TesteConexao {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/sakila";
        String user = "root";
        String password = "#Mysql#10@10";

        try (Connection conn = DriverManager.getConnection (
                        url , user , password ) ) {
            System.out.println (" Conexao estabelecida com sucesso !") ;
            // Teste simples
            Statement stmt = conn.createStatement () ;
            ResultSet rs = stmt.executeQuery(" SELECT * FROM actor;");

        }catch (SQLException e){
            System.out.println("Erro de conexao: " + e.getMessage());
        }
    }
}
