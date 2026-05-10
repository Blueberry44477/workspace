package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import java.util.List;

import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;


public interface AuthorRepository extends JpaRepository<Author, Long> {
    @NonNull
    @EntityGraph(attributePaths = {"articles"})
    List<Author> findAll();
}