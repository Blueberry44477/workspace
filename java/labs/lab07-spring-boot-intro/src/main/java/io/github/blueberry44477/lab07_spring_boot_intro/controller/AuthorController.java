package io.github.blueberry44477.lab07_spring_boot_intro.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab07_spring_boot_intro.model.Author;
import io.github.blueberry44477.lab07_spring_boot_intro.service.AuthorService;
import lombok.RequiredArgsConstructor;

import java.util.Set;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseStatus;


@RestController
@RequestMapping("/api/v1/author")
@RequiredArgsConstructor
public class AuthorController {
    private final AuthorService service;

    @GetMapping
    public Set<Author> getAuthors() {
        return service.getAuthors();
    }
    

    @GetMapping("/{id}")
    public ResponseEntity<Author> getAuthorById(@PathVariable String id) {
        return ResponseEntity.ok(service.getAuthorById(id));
    }

    @PostMapping
    public ResponseEntity<Author> addAuthor(@RequestBody Author author) {
        service.addAuthor(author);
        return new ResponseEntity<>(author, HttpStatus.CREATED);
    }

    @DeleteMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void deleteAuthorById(@PathVariable String id) {
        service.deleteAuthorById(id);
    }

    @PutMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void updateAuthor(@PathVariable String id, @RequestBody Author author) {
        author.setId(id);
        service.updateAuthor(author);
    }

    @PatchMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void patchAuthor(@PathVariable String id, @RequestBody Author author) {
        author.setId(id);
        service.patchAuthor(author);
    }
}
