package io.github.blueberry44477.lab08_spring_boot_rest.model;

import java.util.ArrayList;
import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.NonNull;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Subscriber {
    @NonNull private String id;
    private String name;
    private Plan plan;
    private String formatPreference;

    private List<Topic> topics = new ArrayList<>();
}
