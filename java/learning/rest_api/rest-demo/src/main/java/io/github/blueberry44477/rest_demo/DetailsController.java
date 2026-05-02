package io.github.blueberry44477.rest_demo;

import java.util.ArrayList;
import java.util.List;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.PathVariable;

@RestController
@RequestMapping("/api/details")
public class DetailsController {
    private List<Details> detailsList = new ArrayList<>();

    @GetMapping
    public List<Details> getAllDetails() {
        return detailsList;
    }

    @PostMapping
    public String addDetails(@RequestBody Details details) {
        detailsList.add(details);
        return "Data Inserted";
    }

    @PutMapping("/{id}")
    public String updateDetails(@PathVariable String id, @RequestBody Details updatedDetails) {
        for (Details details : detailsList) {
            if (details.getId().equals(id)) {
                details.setName(updatedDetails.getName());
                return "Data updated";
            }
        }
        return "Detail not found";
    }

    @DeleteMapping("/{id}")
    public String deleteDetails(@PathVariable String id) {
        boolean removed = detailsList.removeIf(details -> details.getId().equals(id));
        return removed ? "Data Deleted Successfully" : "Detail not found";
    }
}
