package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import lombok.RequiredArgsConstructor;
import org.apache.commons.lang3.StringUtils;
import org.apache.tomcat.util.http.fileupload.IOUtils;

import org.springframework.core.io.ClassPathResource;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.AuthorDto;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Repository
@RequiredArgsConstructor
public class JdbcTemplateAuthorsRepository {
    public static final String QUERY_NAME = "get_all_authors";
    private final JdbcTemplate jdbcTemplate;

    public List<AuthorDto> getAllAuthors() {
        Map<String, Object> params = new HashMap<>();
        params.put("limit", "10");
        params.put("offset", "0");

        String sqlQuery = getSqlQuery(QUERY_NAME, params);
        List<AuthorDto> authors = jdbcTemplate.query(sqlQuery, (rs, rowNum) -> new AuthorDto(
            rs.getLong("id"),
            rs.getString("name"),
            rs.getString("bio")
        ));

        return authors;
    }

    private String getSqlQuery(String queryName, Map<String, ?> placeholders) {
        String queryFilePath = String.format("/queries/%s.sql", queryName);
        ClassPathResource classPathResource = new ClassPathResource(queryFilePath);
        OutputStream writer = new ByteArrayOutputStream();
        try (var inputStream = classPathResource.getInputStream()) {
            IOUtils.copy(inputStream, writer);
        } catch (IOException ex) {
            throw new RuntimeException("Failed to load SQL file: " + queryFilePath, ex);
        }
        String result;
        if (placeholders.isEmpty()) {
            result = writer.toString();
        } else {
            String[] keys = placeholders.keySet().stream().map(keyName -> String.format("${%s}", keyName)).toArray(String[]::new);
            String[] values = placeholders.values().stream().map(String::valueOf).toArray(String[]::new);
            result = StringUtils.replaceEach(writer.toString(), keys, values);
        }
        return result;
    }

}
