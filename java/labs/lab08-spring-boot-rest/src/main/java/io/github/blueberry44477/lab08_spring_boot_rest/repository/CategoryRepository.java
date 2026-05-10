package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import java.util.List;

import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Category;

public interface CategoryRepository extends JpaRepository<Category, Long> {
    @NonNull
    @EntityGraph(attributePaths = {"parent"})
    List<Category> findAll();
}
