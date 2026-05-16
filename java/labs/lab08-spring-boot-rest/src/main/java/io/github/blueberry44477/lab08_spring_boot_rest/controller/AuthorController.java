package io.github.blueberry44477.lab08_spring_boot_rest.controller;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.AuthorDto;
import io.github.blueberry44477.lab08_spring_boot_rest.dto.request.CreateAuthorRequest;
import io.github.blueberry44477.lab08_spring_boot_rest.service.AuthorService;

import io.swagger.v3.oas.annotations.Operation;
import io.swagger.v3.oas.annotations.Parameter;
import io.swagger.v3.oas.annotations.media.ArraySchema;
import io.swagger.v3.oas.annotations.media.Schema;
import io.swagger.v3.oas.annotations.media.Content;
import io.swagger.v3.oas.annotations.tags.Tag;
import io.swagger.v3.oas.annotations.responses.ApiResponse;

import lombok.RequiredArgsConstructor;

import java.util.List;

import org.springdoc.core.annotations.ParameterObject;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.data.web.PageableDefault;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.lang.NonNull;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseStatus;

@Tag(name = "Author",
     description = "Controller to manipulate all entities related to authors")
@RestController
@RequestMapping("/api/v1/author")
@RequiredArgsConstructor
public class AuthorController {
    private final AuthorService service;

    @Operation(
        summary = "Retrieve authors page",
        responses = {
            @ApiResponse(
                responseCode = "200",
                description = "Successfully retrieved the list of authors",
                content = @Content(array = @ArraySchema(schema = @Schema(implementation = AuthorDto.class)))
            )
        }
    )
    @GetMapping(produces = MediaType.APPLICATION_JSON_VALUE)
    public Page<AuthorDto> getAuthors(
        @ParameterObject @PageableDefault(page = 0, size = 10, sort = "id") 
        @NonNull Pageable pageable
    ) {
        return service.getAuthors(pageable);
    }
    
    @Operation(
        summary = "Get author by ID",
        responses = {
            @ApiResponse(
                responseCode = "200",
                description = "Author successfully found and returned",
                content = @Content(schema = @Schema(implementation = AuthorDto.class))
            ),
            @ApiResponse(
                responseCode = "404",
                description = "No author details could be found matching the provided ID",
                content = @Content
            )
        }
    )
    @GetMapping(value = "/{id}", produces = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<AuthorDto> getAuthorById(
        @Parameter(required = true, example = "101")
        @PathVariable Long id
    ) {
        return ResponseEntity.ok(service.getAuthorById(id));
    }

    @Operation(
        summary = "Create a new author",
        responses = {
            @ApiResponse(
                responseCode = "201",
                description = "Author created successfully",
                content = @Content(schema = @Schema(implementation = AuthorDto.class))
            ),
            @ApiResponse(
                responseCode = "400", 
                description = "Invalid input data provided", 
                content = @Content
            )
        }
    )
    @PostMapping(consumes = MediaType.APPLICATION_JSON_VALUE)
    public ResponseEntity<AuthorDto> addAuthor(
        @io.swagger.v3.oas.annotations.parameters.RequestBody(
            description = "Author's information",
            required = true,
            content = @Content(schema = @Schema(implementation = CreateAuthorRequest.class))
        )
        @RequestBody CreateAuthorRequest request
    ) {
        return ResponseEntity.status(HttpStatus.CREATED).body(service.addAuthor(request));
    }

    @PostMapping("/batch")
    public ResponseEntity<List<AuthorDto>> addAuthors(
        @RequestBody List<AuthorDto> authorDtoList
    ) {
        return new ResponseEntity<>(service.addAuthors(authorDtoList), HttpStatus.CREATED);
    }

    @Operation(
        summary = "Delete an author by ID",
        responses = {
            @ApiResponse(responseCode = "204", description = "Author removed successfully, no content body returned"),
            @ApiResponse(responseCode = "404", description = "Author search record target not found, execution aborted")
        }
    )
    @DeleteMapping("/{id}")
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void deleteAuthorById(
        @Parameter(required = true, example = "101")
        @PathVariable Long id
    ) {
        service.deleteAuthorById(id);
    }

    @Operation(
        summary = "Replace entire author dataset (Put)",
        description = "Performs full field override replacements over the specified author ID. Missing body parameter fields will null out existing values.",
        responses = {
            @ApiResponse(responseCode = "204", description = "Author updated completely, structure sync successful"),
            @ApiResponse(responseCode = "404", description = "No matching author record found to replace")
        }
    )
    @PutMapping(value = "/{id}", consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void updateAuthor(
        @Parameter(required = true, example = "101")
        @PathVariable Long id, 
        @RequestBody AuthorDto authorDto
    ) {
        service.updateAuthor(id, authorDto);
    }

    @Operation(
        summary = "Partially update author fields (Patch)",
        responses = {
            @ApiResponse(responseCode = "204", description = "Target fields updated successfully"),
            @ApiResponse(responseCode = "404", description = "Specified author tracking target profile lookup completely missing")
        }
    )
    @PatchMapping(value = "/{id}", consumes = MediaType.APPLICATION_JSON_VALUE)
    @ResponseStatus(HttpStatus.NO_CONTENT)
    public void patchAuthor(
        @Parameter(required = true, example = "101")
        @PathVariable Long id, 

        @io.swagger.v3.oas.annotations.parameters.RequestBody(
            description = "Author's information",
            required = true,
            content = @Content(schema = @Schema(implementation = AuthorDto.class))
        )
        @RequestBody AuthorDto authorDto
    ) {
        service.patchAuthor(id, authorDto);
    }
}
