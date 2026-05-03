package io.github.blueberry44477.lab07_spring_boot_intro.model;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Plan {
    private String id;
    private Integer dailyLimit;
}
