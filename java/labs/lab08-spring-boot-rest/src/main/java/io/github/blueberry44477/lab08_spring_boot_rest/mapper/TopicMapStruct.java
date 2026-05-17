package io.github.blueberry44477.lab08_spring_boot_rest.mapper;

import java.util.List;

import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.response.TopicDto;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Topic;

@Mapper(
    componentModel = "spring"
    // uses = {ArticleMapStruct.class}
)
public interface TopicMapStruct {
    @Mapping(target = "articles", ignore = true)
    TopicDto toDto(Topic entity);
    List<TopicDto> toDtoList(List<Topic> topics);

    Topic toEntity(TopicDto topicDto);
    List<Topic> toEntityList(List<TopicDto> topicDtoList);
}
