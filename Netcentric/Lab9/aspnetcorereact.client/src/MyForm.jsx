import React, { useState } from "react";
import "bootstrap/dist/css/bootstrap.min.css";

function MyForm() {
    const [formData, setFormData] = useState({
        name: "",
        email: "",
        password: ""
    });

    const [errors, setErrors] = useState({});

    const validateForm = () => {
        const newErrors = {};

        if (!formData.name.trim())
            newErrors.name = "Name is required";

        if (!formData.email) {
            newErrors.email = "Email is required";
        } else if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(formData.email)) {
            newErrors.email = "Invalid email format";
        }

        if (!formData.password) {
            newErrors.password = "Password is required";
        } else if (formData.password.length < 6) {
            newErrors.password = "Minimum 6 characters required";
        }

        setErrors(newErrors);
        return Object.keys(newErrors).length === 0;
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        if (validateForm()) {
            alert("Form submitted successfully!");
            console.log(formData);
        }
    };

    const handleChange = (e) => {
        const { name, value } = e.target;
        setFormData(prev => ({ ...prev, [name]: value }));
    };

    return (
        <div className="flex items-center justify-center min-h-screen bg-gray-50 px-2">
            <div className="w-full max-w-sm bg-white p-6 sm:p-8 rounded-md shadow-md border border-blue-400">
                <div className="card shadow-lg border-0 rounded-4">

                    {/* Header */}
                    <div className="card-header text-center bg-dark text-white rounded-top-4 py-3">
                        <h4 className="mb-0 fw-bold">User Registration</h4>
                        <small className="text-secondary">Create your account</small>
                    </div>

                    {/* Body */}
                    <div className="card-body p-4">
                        <form onSubmit={handleSubmit} noValidate>

                            {/* Name */}
                            <div className="mb-3">
                                <label className="form-label fw-semibold">Name</label>
                                <input
                                    type="text"
                                    name="name"
                                    className={`form-control form-control-lg rounded-3 ${errors.name ? "is-invalid" : ""
                                        }`}
                                    value={formData.name}
                                    onChange={handleChange}
                                    placeholder="Enter your name"
                                />
                                <div className="invalid-feedback">{errors.name}</div>
                            </div>

                            {/* Email */}
                            <div className="mb-3">
                                <label className="form-label fw-semibold">Email</label>
                                <input
                                    type="email"
                                    name="email"
                                    className={`form-control form-control-lg rounded-3 ${errors.email ? "is-invalid" : ""
                                        }`}
                                    value={formData.email}
                                    onChange={handleChange}
                                    placeholder="Enter your email"
                                />
                                <div className="invalid-feedback">{errors.email}</div>
                            </div>

                            {/* Password */}
                            <div className="mb-4">
                                <label className="form-label fw-semibold">Password</label>
                                <input
                                    type="password"
                                    name="password"
                                    className={`form-control form-control-lg rounded-3 ${errors.password ? "is-invalid" : ""
                                        }`}
                                    value={formData.password}
                                    onChange={handleChange}
                                    placeholder="Enter password"
                                />
                                <div className="invalid-feedback">{errors.password}</div>
                            </div>

                            {/* Button */}
                            <button
                                type="submit"
                                className="btn btn-dark btn-lg w-100 rounded-3 fw-semibold"
                            >
                                Register
                            </button>

                            <div className="text-center mt-3">
                                <p className="mb-0 text-muted">
                                     {new Date().getFullYear()} Made by : Surajan Shrestha
                                </p>
                            </div>


                        </form>
                    </div>
                </div>
            </div>
        </div>
    );
}

export default MyForm;
