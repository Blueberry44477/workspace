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
public class Article {
    @NonNull private String id;
    private String title;
    private String content;

    private Author author;
    private Category category;

    private List<Topic> topics = new ArrayList<>();
    private List<Keyword> keywords = new ArrayList<>();
}
