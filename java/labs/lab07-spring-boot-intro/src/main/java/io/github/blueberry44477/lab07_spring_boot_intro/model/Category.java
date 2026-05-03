package io.github.blueberry44477.lab07_spring_boot_intro.model;

import com.fasterxml.jackson.annotation.JsonBackReference;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.NonNull;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Category {
    @NonNull private String id;
    @NonNull private String name;

    @JsonBackReference
    private Category parent;
}
