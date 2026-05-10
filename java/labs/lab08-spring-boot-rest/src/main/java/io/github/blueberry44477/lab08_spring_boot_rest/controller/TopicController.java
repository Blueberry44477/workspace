package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import java.util.List;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.TopicDto;
import io.github.blueberry44477.lab08_spring_boot_rest.service.TopicService;
import lombok.RequiredArgsConstructor;

@RestController
@RequiredArgsConstructor
@RequestMapping("api/v1/topic")
public class TopicController {
    private final TopicService service;

    @GetMapping
    public List<TopicDto> getTopics() {
        return service.getTopics();
    }

    @PostMapping
    public ResponseEntity<TopicDto> addTopic(@RequestBody TopicDto topicDto) {
        return new ResponseEntity<>(service.addTopic(topicDto), HttpStatus.CREATED);
    }

    @PostMapping("/batch")
    public ResponseEntity<List<TopicDto>> addTopics(
        @RequestBody List<TopicDto> topicDtoList
    ) {
        return new ResponseEntity<>(service.addTopics(topicDtoList), HttpStatus.CREATED);
    }
}
