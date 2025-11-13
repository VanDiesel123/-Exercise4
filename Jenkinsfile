pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure CMake') {
            steps {
                bat '''
                cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug
                '''
            }
        }

        stage('Build') {
            steps {
                bat '''
                cmake --build build -j
                '''
            }
        }

        stage('Run Tests') {
            steps {
                bat '''
                build\\runTests.exe --gtest_output=xml:build/test_reports/test_report.xml
                '''
            }
        }
    }

    post {
        always {
            // Звіт тепер теж без Lab4/
            junit 'build/test_reports/*.xml'
        }
    }
}
