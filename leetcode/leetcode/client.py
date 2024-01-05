import typing as tp

import requests


class Client:
    URL = "https://leetcode.com/graphql"

    def _post(self, json: dict[str, tp.Any]) -> dict[str, tp.Any]:
        response = requests.post(self.URL, json=json)
        return response.json()

    def question_list(
        self,
        category_slug: str = "",
        limit: int = 50,
        skip: int = 0,
        filters: dict[str, str] = {},
    ) -> dict[str, tp.Any]:
        query = """
        query problemsetQuestionList(
            $categorySlug: String,
            $limit: Int,
            $skip: Int,
            $filters: QuestionListFilterInput) {
                problemsetQuestionList: questionList(
                categorySlug: $categorySlug
                limit: $limit
                skip: $skip
                filters: $filters
            ) {
                total: totalNum
                questions: data {
                    acRate
                    difficulty
                    freqBar
                    frontendQuestionId: questionFrontendId
                    isFavor
                    paidOnly: isPaidOnly
                    status
                    title
                    titleSlug
                    topicTags {
                        name
                        id
                        slug
                    }
                    hasSolution
                    hasVideoSolution
                }
            }
        }
        """

        data = {
            "operationName": "problemsetQuestionList",
            "variables": {
                "categorySlug": category_slug,
                "limit": limit,
                "skip": skip,
                "filters": filters,
            },
            "query": query,
        }

        return self._post(data)

    def question_data(self, slug: str) -> dict[str, tp.Any]:
        query = """
        query questionData($titleSlug: String!) {
            question(titleSlug: $titleSlug) {
                questionId
                questionFrontendId
                title
                titleSlug
                difficulty
                isPaidOnly
                content
                codeSnippets {
                    langSlug
                    code
                }
                topicTags {
                    name
                }
                metaData
                exampleTestcaseList
            }
        }
        """

        data = {
            "operationName": "questionData",
            "variables": {"titleSlug": slug},
            "query": query,
        }

        return self._post(data)

    def question_of_today(self) -> dict[str, tp.Any]:
        query = """
        query questionOfToday {
            activeDailyCodingChallengeQuestion {
                date
                userStatus
                link
                question {
                    acRate
                    difficulty
                    freqBar
                    questionFrontendId
                    isFavor
                    isPaidOnly
                    status
                    title
                    titleSlug
                    hasVideoSolution
                    hasSolution
                    topicTags {
                        name
                        id
                        slug
                    }
                }
            }
        }
        """

        data = {
            "query": query,
        }

        return self._post(data)
