// // package io.github.blueberry44477.lab08_spring_boot_rest.mapper.manual;

// package io.github.blueberry44477.lab08_spring_boot_rest.mapper.manual;

// import io.github.blueberry44477.lab08_spring_boot_rest.annotations.ManualMapper;
// import io.github.blueberry44477.lab08_spring_boot_rest.dto.AuthorDto;
// import io.github.blueberry44477.lab08_spring_boot_rest.model.Author;

// @ManualMapper
// public class AuthorMapper {
//     public AuthorDto toDto(Author entity) {
//         if (entity == null) {
//             return null;
//         }
//         return new AuthorDto().setId(entity.getId())
//                               .setEmail(entity.getEmail())
//                               .setPhone(entity.getPhone())
//                               .setFirstName(entity.getFirstName())
//                               .setLastName(entity.getLastName());
//     }

//     public Author toEntity(AuthorDto dto) {
//         if (dto == null) {
//             return null;
//         }
//         return new Author()
//                 .setEmail(dto.getEmail())
//                 .setPhone(dto.getPhone())
//                 .setFirstName(dto.getFirstName())
//                 .setLastName(dto.getLastName())
//                 .setId(dto.getId());
//     }
// }

