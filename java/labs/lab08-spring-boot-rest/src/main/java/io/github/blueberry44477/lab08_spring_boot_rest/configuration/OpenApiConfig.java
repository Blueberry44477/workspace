package io.github.blueberry44477.lab08_spring_boot_rest.configuration;

import java.util.List;

import org.springdoc.core.models.GroupedOpenApi;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import io.swagger.v3.oas.models.OpenAPI;
import io.swagger.v3.oas.models.info.Contact;
import io.swagger.v3.oas.models.info.Info;
import io.swagger.v3.oas.models.info.License;
import io.swagger.v3.oas.models.servers.Server;

@Configuration
public class OpenApiConfig {
    @Bean
    public OpenAPI customOpenAPI() {
        return new OpenAPI()
            .info(new Info()
                .title("My API Documentation")
                .version("1.0.0")
                .description(null)
                .contact(new Contact().name("blueberry").email("blueberry@gmail.com"))
                .license(new License().name("Apache 2.0").url("http://springdoc.org"))
            )
            // .servers(Collections.emptyList());
            .servers(List.of(new Server().url("?").description("")));
    }

    @Bean
    public GroupedOpenApi defaultApi() {
        return GroupedOpenApi.builder()
            .group("0. All modules")
            .pathsToMatch("/**")
            .build();
    }

    @Bean
    public GroupedOpenApi authorApi() {
        return GroupedOpenApi.builder()
            .group("1. Author module")
            .pathsToMatch("/api/v1/author/**")
            .build();
    }
    @Bean
    public GroupedOpenApi articleApi() {
        return GroupedOpenApi.builder()
            .group("2. Article module")
            .pathsToMatch("/api/v1/article/**")
            .build();
    }
    @Bean
    public GroupedOpenApi categoryApi() {
        return GroupedOpenApi.builder()
            .group("3. Category module")
            .pathsToMatch("/api/v1/category/**")
            .build();
    }
    @Bean
    public GroupedOpenApi topicApi() {
        return GroupedOpenApi.builder()
            .group("4. Topic module")
            .pathsToMatch("/api/v1/topic/**")
            .build();
    }
    @Bean
    public GroupedOpenApi keywordApi() {
        return GroupedOpenApi.builder()
            .group("5. Keyword module")
            .pathsToMatch("/api/v1/keyword/**")
            .build();
    }
}
