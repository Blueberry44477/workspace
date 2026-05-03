package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.Set;

import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.AuthorRepository;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@Service
@RequiredArgsConstructor
public class AuthorService {
    private final AuthorRepository repository;

    public Set<Author> getAuthors() {
        log.info("Extracting authors from mocked repository");
        return repository.getAuthors();
    }

    public Author getAuthorById(String id) {
        log.info("Extracting authors by id from mocked repository");
        return repository.getAuthorById(id);
    }

    public void addAuthor(Author author) {
        log.info("Adding author {}", author);
        repository.addAuthor(author);
    }

    public void deleteAuthorById(String id) {
        log.info("Deleting author {}", id);
        repository.deleteAuthorById(id);
    }

    public void updateAuthor(Author author) {
        log.info("Performing full update for author {}", author.getId());
        repository.updateAuthor(author);
    }

    public void patchAuthor(Author author) {
        log.info("Patching author {}", author.getId());

        Author existing = repository.getAuthorById(author.getId());

        if (author.getName() != null) {
            existing.setName(author.getName());
        }
        if (author.getBio() != null) {
            existing.setBio(author.getBio());
        }

        repository.updateAuthor(existing);
    }
}
