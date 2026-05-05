package io.github.blueberry44477.lab08_spring_boot_rest.model;

import com.fasterxml.jackson.annotation.JsonBackReference;

import jakarta.persistence.Entity;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.NonNull;
import lombok.Setter;
import lombok.experimental.Accessors;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
@Entity
@Accessors(chain = true)
@Table(name = "category")
public class Category {
    @Id
    private Long id;

    @NonNull private String name;
    
    @ManyToOne
    @JsonBackReference
    @JoinColumn(name = "parent_id")
    private Category parent;
}
