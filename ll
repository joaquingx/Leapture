P] BB-903 : value error input data

Issue: https://emptor-dev.atlassian.net/browse/BB-903

**PR Changes:**

*List of major changes:*

- [x] Make requested changes


**PR Checklist:**

*Before submitting to review, I have:*

- [x] Used the same [coding conventions][5] as the rest of the project.
- [x] Written [good commit messages][1].
- [x] [Squashed related commits together][2].
- [x] Ensured docstrings follow [NumPy Style convention][3].
- [x] Added [unit tests][6] (if applicable).
- [x] Added [integration tests][7] (if applicable).
- [x] Ensured all [unit tests][6] (`make test`) are passing.
- [x] Ensured the new code does not generate [lint][8] (`make lint`) offenses.
- [x] Used [branch name prefix][9] `<ISSUE_ID>` (if a related task exists).
- [x] Used [PR title prefix][9] `[MRG] <ISSUE_ID>:` (if a related task exists).
- [x] Ensured the PR title and description are clear and in grammatically correct, complete sentences.
- [x] The PR link as been added as comment to the related Asana task (if applicable).
- [x] Sent review request to [#please-review][4] channel.

_Note: Spider classes do not require unit tests._

**Spiders Checklist:** (if applicable)

*Before submitting to review, I have:*

- [x] Added as snippet the JSON output in [#please-review][4] (`scrapy crawl ... -t json -o - | jq . > items.json`).
- [x] Added as comment the related `scrapy` command to the output snippet in [#please-review][4].
- [x] Added as comment in this PR the link to the output snippet in [#please-review][4].

**Merge Checklist:**

*Before merging, for PR reviewers:*

- [ ] Has at least one review.
- [ ] Spider output has been reviewed (if applicable).

[1]: http://chris.beams.io/posts/git-commit/
[2]: https://github.com/emptor/bgcspiders#rebasing-and-squashing
[3]: https://sphinxcontrib-napoleon.readthedocs.io/en/latest/example_numpy.html
[4]: https://emptor.slack.com/channels/please-review
[5]: https://github.com/emptor/bgcspiders#development
[6]: https://github.com/emptor/bgcspiders#unit-tests
[7]: https://github.com/emptor/bgcspiders#integration-tests
[8]: https://github.com/emptor/bgcspiders#code-quality
[9]: https://github.com/emptor/bgcspiders#pull-requests

