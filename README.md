# Embedded Systems Geeks Guadalajara (ESG/GDL)

This repository provides an open collaboration space for members of the ESG meetup group in
Guadalajara, Mexico. ESG members are encouraged to share examples, ideas, and projects here,
related to embedded systems programming, engineering and development.
We shall moreover use this repository for making available slides and other resources of ESG
talks, seminars and workshops. If you like to join the community, make sure that you become
a member of our group on meetup.com:

https://www.meetup.com/embedded-systems-geeks-gdl/

Future meetups, socials and workshops will be advertised via the above meetup group.

In addition, ping the repository owner (Frank Zeyda) to be added to the ESG WhatsApp channel.
This is where we share updates, plan future meetups, and connect with the community. We also
appreciate offers of talks/workshops and sponsorship for future meetups. We are hoping to
grow the community in the upcoming year, and this repository is part of that objective and
to help us on our way by attracting new members, learn together, and start to collaborate.

Please read carefully through this document before starting to contribute and push material
into the repository. Non-ESG members members stumbling across here ought be aware that this
repository largely contains experimental code rather than & in addition to finished projects
and products.

## Repository Content & Structure

The repository is organized into various directories to structure the content.

| Directory | Description |
| --------- | ----------- |
| `meetups` | Material related to previous meetings, such as slides, code, examples, etc. |
| `members` | Area for members to create subfolders to share their personal work |
| `collaboration` | Collaboration space: use this to collaborate on new ideas and projects |
| `showcase` | Special area to showcase some cool (finished) projects of ESG in the future |
| `resources` | Collection of links, notes and PDFs providing useful resources |
| `organization` | Relevant documents and notes related to ESG organizational matters |
| `socialmedia` | Material relevant for advertising and growing ESG on social media |

Here are a few more notes on how to use these directories appropriately:
- In `meetups`, you will find the subfolders `slides` and `examples`.
  - For those who gave a talk, please upload your slides (if possible) as a PDF to the `slides` folder.
  - For those who gave a talk, please upload your examples (if possible) into the `examples` folder.<br/>
    (If your example source code consists of several files, please create a suitable subfolder for them.
- In `members`, please create a directory with your name to share personal projects.<br/>
  - E.g., `fzeyda` for Frank Zeyda or `jhernandez` for Josue Hernandez, and so on.
  - Predominately use this folder for material that you like to share with the group, but not necessarily
    like to collaborate on.
- In `collaboration`, please create a directory for each idea or projects that you like to collaborate
  on with other ESG members.
  - I already added something there related to writing a SSD1306 OLED driver for Arduino with low memory
    footprint.
  - Feel free to add to this, choosing a suitable folder name for your project - we love to have more
    stuff there in the future.
- In `resources`, feel free to upload material such as markdown files with useful links, datasheets,
  presentations, etc. Be aware of copyright and license issues before sharing material there
  (otherwise, a link in the `README.md` of that subfolder may be more appropriate).
- The `organization` folder will be mostly maintained by myself, adding information there wrt sponsors,
  finances, future plans, and so on. Feel free to periodically check the content but no need to add
  things there (unless you happen to be involved in organizational matters, which would be great too
  &mdash; let's have a chat if you are keen).
- The `socialmedia` folder can be used, for instance, to share photos and other social-media
  relevant materials. Perhaps also logos, templates, as well as links to other places where we might
  want to promote the group (LinkedIn, Facebook, Instagram, and so on).

As said, everyone is encouraged to contribute &mdash; you do not have to check with me before pushing
material, subject to respecting the contribution policy and guidelines below.
I would only ask contributors to keep the repository clean and uncluttered, choosing suitable names
for subfolders and considering what needs to be pushed. Be aware that this is a public repository,
so do not share anything that you prefer to be kept copyrighted or private.

## Contribution Policy & Guidelines

As I presume projects will be comparably small in size, I suggest to adopt lightweight trunk-based
development in `collaboration` rather than GitFlow. That is, pushing directly into the `main`
branch rather than creating a separate feature branch for each small contribution. There is
currently no setup for CI/CD but contributors should verify that their contributions at least
compile locally without any errors, and provide information on required tools and their versions. I
leave it to the collaboration team to decide whether all commits should be done via merge requests (MRs)
or are eligible to push directly into `main` (e.g., if you trust your collaborators and do not have
the time for detailed reviews). Thus I do not want to constrain any collaboration team in how they
prefer to work, in particular, those that may not be extremely familiar with styles of collaborative
development. Monitoring how that works, we might refine the workflow requirements in the future,
including CI/CD setup.

As a checklist, contributors are encouraged to:
- create at least one issue for each project. We also have a GitLab project for ESG
  here: https://github.com/users/Frank-Zeyda/projects/4, so feel free to make use of
  that in order to plan and delegate tasks and work
- generally, feel free to make use of issues and discussions to communicate ideas,
  identify tasks, and collaborate
- only upload/commit what actually needs to be committed (e.g., no dynamic files created
  during compilation or residual backup files)
- provide a documentation (`README.md`) for each project and also for your member folder
- verify that published code compiles and provide information on required tools and their
  versions (e.g., tested with version X.Y.Z of the Arduino IDE, requires this board, etc.)
- write short but meaningful commit messages
- be respectful, kind and supportive to other members and collaborators, in particular,
  when replying to issues and writing commit messages, e.g., to fix bugs

Otherwise, I do not want to constrain how ESG members use the repository. In particular,
we should not just use it to share code and hardware designs, but also:
- share interesting discussions and questions
- kick-start collaborations even based on a few sketchy ideas
- share code that might yet be in a preliminary stage
- invite friends and colleagues from networks and companies outside ESG
- freely use the `showcase` area if you have a nifty finished project that you like to share

Note on `showcase`: here, please put more effort into documentation and perhaps also the
underlying hardware design, adding diagrams and images, if possible, for others to recreate
you design.

If you have any questions or concerns, please feel to ping Frank Zeyda or otherwise
raise them in the ESG WhatsApp channel.

Happy coding, designing and collaborating! 😊

## License

All material in this repository is published under the [MIT license](https://opensource.org/license/mit/).
The MIT license is one of the most permissive and (legally) least complex open-source license: basically,
it allows anyone to do whatever they like with your code, albeit relieving the authors from any kind of
warranty or liability. Please bear this in mind before uploaded/publishing your projects here.
