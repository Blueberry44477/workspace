package io.github.blueberry44477.authentication;

import io.github.blueberry44477.DbConnector;

import java.util.Optional;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import org.mindrot.jbcrypt.BCrypt;

public class DbAuthManager {
    public Optional<User> authenticateUser(String username, String plainTextPassword) {
        String sql = "SELECT id, password_hash FROM users WHERE username = ?";

        try (Connection connection = DbConnector.getConnection();
             PreparedStatement pstmt = connection.prepareStatement(sql)) {
            
            pstmt.setString(1, username);

            try (ResultSet result = pstmt.executeQuery()) {
                if (result.next()) {
                    String storedHash = result.getString("password_hash");
                    
                    if (BCrypt.checkpw(plainTextPassword, storedHash)) {
                        int userId = result.getInt("id");
                        User loggedUser = new User(userId, username);

                        return Optional.of(loggedUser);
                    }
                }
            }
        } catch (Exception e) {
            e.getStackTrace();
        }
        
        return Optional.empty();
    }
}
