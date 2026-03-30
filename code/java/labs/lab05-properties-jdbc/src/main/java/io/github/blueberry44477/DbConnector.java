package io.github.blueberry44477;

import java.io.InputStream;
import java.util.Properties;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.DriverManager;

public class DbConnector {
    private static final String propertiesFilename = "db.properties";
    private static final Properties properties = new Properties();

    static {
        loadProperties();
    }

    private static void loadProperties() {
        // Search from the project root (instead of relative search like "new FileInputStream(filename)")
        try (InputStream input = DbConnector.class.getClassLoader().getResourceAsStream(propertiesFilename)) {
            properties.load(input);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(
            properties.getProperty("db.url"),
            properties.getProperty("db.user"),
            properties.getProperty("db.password")
        );
    }
}