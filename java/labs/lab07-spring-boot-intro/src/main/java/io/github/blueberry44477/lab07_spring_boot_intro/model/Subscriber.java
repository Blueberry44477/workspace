package io.github.blueberry44477.lab07_spring_boot_intro.model;

import java.util.ArrayList;
import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
@NoArgsConstructor
public class Subscriber {
    private String id;
    private String name;
    private Plan plan;
    private String formatPreference;

    private List<Topic> topics = new ArrayList<>();
}
