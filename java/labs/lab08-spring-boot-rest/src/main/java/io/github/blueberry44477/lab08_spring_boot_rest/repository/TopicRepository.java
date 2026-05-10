package io.github.blueberry44477.lab08_spring_boot_rest.repository;

import java.util.List;

import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.lang.NonNull;

import io.github.blueberry44477.lab08_spring_boot_rest.model.Topic;
 
public interface TopicRepository extends JpaRepository<Topic, Long> {
    @NonNull
    @EntityGraph(attributePaths = {"articles"})
    List<Topic> findAll();
}
