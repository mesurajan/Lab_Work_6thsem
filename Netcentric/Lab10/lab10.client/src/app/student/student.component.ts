import { Component } from '@angular/core';
import { FormControl, FormGroup, Validators } from '@angular/forms';

@Component({
  selector: 'app-student',
  templateUrl: './student.component.html'
})
export class StudentComponent {

  studentForm = new FormGroup({
    firstname: new FormControl('', Validators.required)
  });

  formSubmit() {
    if (this.studentForm.valid) {
      alert('Student Name: ' + this.studentForm.value.firstname);
    } else {
      alert('Please enter name');
    }
  }

  get Firstname(): FormControl {
    return this.studentForm.get('firstname') as FormControl;
  }
}
