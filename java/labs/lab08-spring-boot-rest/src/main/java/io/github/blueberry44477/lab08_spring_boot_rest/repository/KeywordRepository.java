package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import java.util.List;

import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;

public interface KeywordRepository extends JpaRepository<Keyword, Long>{
    @NonNull
    @EntityGraph(attributePaths = {"articles"})
    List<Keyword> findAll();

    // @Query("SELECT DISTINCT keyword FROM Keyword keyword LEFT JOIN FETCH keyword.articles")
    // @NonNull
    // List<Keyword> findAll();
}
