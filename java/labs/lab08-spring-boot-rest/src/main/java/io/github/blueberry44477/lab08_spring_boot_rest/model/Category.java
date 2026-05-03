package io.github.blueberry44477.lab08_spring_boot_rest.model;

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
