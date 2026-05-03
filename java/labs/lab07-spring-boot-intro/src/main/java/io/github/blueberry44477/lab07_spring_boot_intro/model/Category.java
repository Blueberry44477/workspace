package io.github.blueberry44477.lab07_spring_boot_intro.model;

import com.fasterxml.jackson.annotation.JsonBackReference;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Category {
    private String id;
    private String name;

    @JsonBackReference
    private Category parent;
}
