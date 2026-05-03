package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import io.github.blueberry44477.lab08_spring_boot_rest.exception.EntityNotFoundException;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;

import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Set;

import org.springframework.stereotype.Repository;

@Repository
public class AuthorRepository {
    private Set<Author> authors = new LinkedHashSet<>(
        Arrays.asList(
            new Author("1", "Bogdan", "")
        )
    );

    public void addAuthor(Author author) { authors.add(author); }

    public Set<Author> getAuthors() { return authors; }

    public Author getAuthorById(String id) {
        return authors.stream()
                      .filter(author -> author.getId().equals(id))
                      .findFirst()
                      .orElseThrow(() -> new EntityNotFoundException("Author", id));
    }

    public void deleteAuthorById(String id) {
        Author author = getAuthorById(id);
        authors.remove(author);
    }

    public void updateAuthor(Author updatedAuthor) {
        Author existingAuthor = getAuthorById(updatedAuthor.getId());
        authors.remove(existingAuthor);
        authors.add(updatedAuthor);
    }

}
