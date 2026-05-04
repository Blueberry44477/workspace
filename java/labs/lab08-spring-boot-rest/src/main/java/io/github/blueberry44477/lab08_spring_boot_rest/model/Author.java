package io.github.blueberry44477.lab08_spring_boot_rest.model;

import java.util.HashSet;
import java.util.Set;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;
import lombok.experimental.Accessors;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@EqualsAndHashCode(onlyExplicitlyIncluded = true) // Only use marked fields.
@Entity
@Accessors(chain=true)
@Table(name = "author")
public class Author {
    @Id
    @EqualsAndHashCode.Include // For comparison only by id.
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;

    private String bio;


    @ManyToMany // One side is the "owner" (where the join table is defined), 
                // and the other is the "inverse" side.
    // Проміжна таблиця.
    @JoinTable(
        name = "author_article",
        joinColumns = @JoinColumn(name = "author_id"),
        inverseJoinColumns = @JoinColumn(name = "article_id")
    )
    @ToString.Exclude // Prevent circular references in logs
    private Set<Article> articles = new HashSet<>();
}
