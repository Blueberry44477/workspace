package io.github.blueberry44477.lab08_spring_boot_rest.service;

import java.util.List;

import org.springframework.stereotype.Service;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.TopicDto;
import io.github.blueberry44477.lab08_spring_boot_rest.mapper.TopicMapStruct;
import io.github.blueberry44477.lab08_spring_boot_rest.model.Topic;
import io.github.blueberry44477.lab08_spring_boot_rest.repository.TopicRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;


@Service
@RequiredArgsConstructor
public class TopicService {
    private final TopicRepository repository;
    private final TopicMapStruct topicMapper;

    public List<TopicDto> getTopics() {
        return topicMapper.toDtoList(repository.findAll());
    }

    @Transactional
    public TopicDto addTopic(TopicDto topicDto) {
        Topic Topic = topicMapper.toEntity(topicDto);
        Topic savedTopic = repository.save(Topic);
        return topicMapper.toDto(savedTopic);
    }

    @Transactional
    public List<TopicDto> addTopics(List<TopicDto> TopicDtoList) {
        List<Topic> TopicList = topicMapper.toEntityList(TopicDtoList);
        List<Topic> savedTopics = repository.saveAll(TopicList);
        return topicMapper.toDtoList(savedTopics);
    }
}
