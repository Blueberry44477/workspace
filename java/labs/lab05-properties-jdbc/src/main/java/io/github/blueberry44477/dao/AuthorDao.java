package io.github.blueberry44477.dao;

import io.github.blueberry44477.dto.Author;
import io.github.blueberry44477.DbConnector;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import java.sql.Connection;
import java.sql.Statement;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.ResultSet;

public class AuthorDao {

    public boolean create(Author author) {
        String sql = "INSERT INTO author (name, bio) VALUES (?, ?)";

        try (Connection conn = DbConnector.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, author.name());
            pstmt.setString(2, author.bio());

            return pstmt.executeUpdate() > 0;
        } catch (SQLException e) {
            return false;
        }
    }

    public Optional<Author> getById(int id) {
        String sql = "SELECT author_id, name, bio FROM author WHERE author_id = ?";

        try (Connection conn = DbConnector.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, id);

            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    return Optional.of(mapResultSetToAuthor(rs));
                }
            }
        } catch (SQLException e) {
            System.err.println("Помилка при отриманні автора: " + e.getMessage());
        }
        return Optional.empty();
    }

    public List<Author> getAll() {
        List<Author> authors = new ArrayList<>();
        String sql = "SELECT author_id, name, bio FROM author";

        try (Connection conn = DbConnector.getConnection();
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                authors.add(mapResultSetToAuthor(rs));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return authors;
    }

    /**
     * Оскільки record незмінний, сюди передається новий об'єкт Author зі старим ID, але новими даними.
     */
    public boolean update(Author author) {
        String sql = "UPDATE author SET name = ?, bio = ? WHERE author_id = ?";

        try (Connection conn = DbConnector.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, author.name());
            pstmt.setString(2, author.bio());
            pstmt.setInt(3, author.authorId());

            return pstmt.executeUpdate() > 0;
        } catch (SQLException e) {
            return false;
        }
    }

    public boolean delete(int id) {
        String sql = "DELETE FROM author WHERE author_id = ?";

        try (Connection conn = DbConnector.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, id);
            return pstmt.executeUpdate() > 0;
        } catch (SQLException e) {
            return false;
        }
    }

    public List<Author> search(String keyword) {
        List<Author> authors = new ArrayList<>();

        String sql = "SELECT author_id, name, bio FROM author WHERE name LIKE ? OR bio LIKE ?";

        try (Connection conn = DbConnector.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            String searchPattern = "%" + keyword + "%";
            pstmt.setString(1, searchPattern);
            pstmt.setString(2, searchPattern);

            try (ResultSet rs = pstmt.executeQuery()) {
                while (rs.next()) {
                    authors.add(mapResultSetToAuthor(rs));
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return authors;
    }

    private Author mapResultSetToAuthor(ResultSet rs) throws SQLException {
        return new Author(
                rs.getInt("author_id"),
                rs.getString("name"),
                rs.getString("bio")
        );
    }
}
