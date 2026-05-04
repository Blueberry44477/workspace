package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Keyword;

public interface KeywordRepository extends JpaRepository<Keyword, Long>{
    
}
