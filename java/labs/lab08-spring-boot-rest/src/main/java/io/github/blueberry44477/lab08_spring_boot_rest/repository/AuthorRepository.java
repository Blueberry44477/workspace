package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;

public interface AuthorRepository extends JpaRepository<Author, Long> {

}