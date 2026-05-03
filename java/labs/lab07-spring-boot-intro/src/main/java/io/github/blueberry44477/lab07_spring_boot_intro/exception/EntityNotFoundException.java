package io.github.blueberry44477.lab07_spring_boot_intro.exception;

public class EntityNotFoundException extends RuntimeException {
    public EntityNotFoundException(String message) {
        super(message);
    }

    public EntityNotFoundException(String entityName, Object id) {
        super(String.format("%s with id [%s] not found", entityName, id));
    }
}
