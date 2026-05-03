package io.github.blueberry44477.lab07_spring_boot_intro.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.NonNull;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Keyword {
    @NonNull private String id;
    private String word;
}
