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
                if exist build rmdir /S /Q build
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
                if not exist build\\test_reports mkdir build\\test_reports
                build\\runTests.exe --gtest_output=xml:build/test_reports/test_report.xml
                '''
            }
        }
    }

    post {
        always {
            junit 'build/test_reports/*.xml'
        }
    }
}
