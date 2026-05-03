package io.github.blueberry44477.lab08_spring_boot_rest.exception.handler;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;

import io.github.blueberry44477.lab08_spring_boot_rest.dto.ApplicationErrorResponse;
import io.github.blueberry44477.lab08_spring_boot_rest.exception.EntityNotFoundException;
import lombok.extern.slf4j.Slf4j;

@Slf4j
@RestControllerAdvice
public class ErrorHandler extends ResponseEntityExceptionHandler {
    @ExceptionHandler(EntityNotFoundException.class)
    public ResponseEntity<ApplicationErrorResponse> handleEntityNotFound(EntityNotFoundException ex) {
        log.error("Resource not found: {}", ex.getMessage());
        return new ResponseEntity<>(
            new ApplicationErrorResponse(ex.getMessage()), 
            HttpStatus.NOT_FOUND
        );
    }
}
