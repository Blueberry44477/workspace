package io.github.blueberry44477.lab08_spring_boot_rest.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.NonNull;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Plan {
    @NonNull private String id;
    private Integer dailyLimit;
}
