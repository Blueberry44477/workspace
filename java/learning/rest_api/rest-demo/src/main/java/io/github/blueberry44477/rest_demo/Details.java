package io.github.blueberry44477.rest_demo;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;

@AllArgsConstructor
@Getter @Setter
public class Details {
    @NonNull private String id;
    private String name;
}