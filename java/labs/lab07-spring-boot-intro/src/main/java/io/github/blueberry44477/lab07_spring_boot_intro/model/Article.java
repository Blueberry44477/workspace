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
public class Article {
    private String id;
    private String title;
    private String content;
    
    private Author author;
    private Category category;

    private List<Topic> topics = new ArrayList<>();
    private List<Keyword> keywords = new ArrayList<>();
}
